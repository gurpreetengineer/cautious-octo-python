import React, { useState } from 'react';

const videos = [
  {
    id: 1,
    title: 'Video 1',
    url: 'https://www.example.com/video1',
  },
  {
    id: 2,
    title: 'Video 2',
    url: 'https://www.example.com/video2',
  },
  {
    id: 3,
    title: 'Video 3',
    url: 'https://www.example.com/video3',
  },
];

function VideoGrid() {
  const [selectedVideo, setSelectedVideo] = useState(null);

  function handleVideoClick(video) {
    setSelectedVideo(video);
  }

  return (
    <div className="video-grid">
      {videos.map((video) => (
        <div
          className="video"
          key={video.id}
          onClick={() => handleVideoClick(video)}
        >
          <h2>{video.title}</h2>
          <img src={`https://www.example.com/thumbnail/${video.id}`} alt={video.title} />
        </div>
      ))}
      {selectedVideo && (
        <div className="selected-video">
          <h2>{selectedVideo.title}</h2>
          <video src={selectedVideo.url} controls></video>
        </div>
      )}
    </div>
  );
}

export default VideoGrid;
