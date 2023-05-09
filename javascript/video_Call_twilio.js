// Create a new Twilio Video room
const room = new Twilio.Video.Room(roomName);

// Join the room
room.join(token);

// Listen for room events
room.on('participantConnected', (participant) => {
  console.log(`Participant ${participant.identity} connected`);

  // Attach participant's video track to DOM
  const remoteVideo = document.createElement('video');
  remoteVideo.autoplay = true;
  participant.on('trackSubscribed', (track) => {
    if (track.kind === 'video') {
      remoteVideo.srcObject = track.mediaStreamTrack;
      document.getElementById('remote-video-container').appendChild(remoteVideo);
    }
  });
});

// Connect to room and add local video track
Twilio.Video.connect(token, { name: roomName }).then((room) => {
  console.log(`Connected to room ${room.name}`);

  // Get local video track
  navigator.mediaDevices.getUserMedia({ video: true, audio: true }).then((mediaStream) => {
    const localVideo = document.getElementById('local-video');
    localVideo.srcObject = mediaStream;

    // Add local video track to room
    const localTracks = Array.from(mediaStream.getTracks()).map((track) => {
      return new Twilio.Video.LocalVideoTrack(track);
    });
    room.localParticipant.publishTracks(localTracks);
  });
}).catch((error) => {
  console.error(`Error connecting to room: ${error.message}`);
});
