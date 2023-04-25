// Get the local video stream
navigator.mediaDevices.getUserMedia({ video: true, audio: true })
  .then((stream) => {
    // Set up a new RTCPeerConnection
    const configuration = { iceServers: [{ urls: 'stun:stun.l.google.com:19302' }] };
    const peerConnection = new RTCPeerConnection(configuration);

    // Add the local stream to the peer connection
    stream.getTracks().forEach((track) => {
      peerConnection.addTrack(track, stream);
    });

    // Create an offer to start the session
    peerConnection.createOffer()
      .then((offer) => {
        // Set the local description and send the offer to the remote peer
        return peerConnection.setLocalDescription(offer);
      })
      .then(() => {
        // Send the offer to the remote peer
        sendOfferToRemotePeer(peerConnection.localDescription);
      })
      .catch((error) => {
        console.error(`Error creating offer: ${error.message}`);
      });

    // Listen for ICE candidates and send them to the remote peer
    peerConnection.addEventListener('icecandidate', (event) => {
      if (event.candidate) {
        sendICECandidateToRemotePeer(event.candidate);
      }
    });

    // Handle ICE candidate messages from the remote peer
    function handleICECandidate(candidate) {
      peerConnection.addIceCandidate(new RTCIceCandidate(candidate));
    }

    // Handle session description messages from the remote peer
    function handleSessionDescription(description) {
      peerConnection.setRemoteDescription(new RTCSessionDescription(description))
        .then(() => {
          // If the description is an offer, create an answer and send it to the remote peer
          if (description.type === 'offer') {
            return peerConnection.createAnswer();
          }
        })
        .then((answer) => {
          if (answer) {
            // Set the local description and send the answer to the remote peer
            return peerConnection.setLocalDescription(answer);
          }
        })
        .then(() => {
          // Send the answer to the remote peer
          sendAnswerToRemotePeer(peerConnection.localDescription);
        })
        .catch((error) => {
          console.error(`Error handling session description: ${error.message}`);
        });
    }

    // Handle data channel messages from the remote peer
    function handleDataChannel(event) {
      const dataChannel = event.channel;
      dataChannel.addEventListener('message', (event) => {
        console.log(`Received message: ${event.data}`);
      });
    }

    // Create a data channel and send a message
    const dataChannel = peerConnection.createDataChannel('myDataChannel');
    dataChannel.addEventListener('open', () => {
      dataChannel.send('Hello, world!');
    });

    // Listen for errors
    peerConnection.addEventListener('error', (error) => {
      console.error(`Peer connection error: ${error.message}`);
    });
  })
  .catch((error) => {
    console.error(`Error getting local media stream: ${error.message}`);
  });
