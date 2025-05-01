import React from 'react';
import { createPost, updatePost, fetchAllPosts, fetchSinglePost, deletePost } from '../utils/api';

const Home = () => {
  // const [createPostResponse, useCreatePostResponse] = useState(null);
  const createPostButton = async () => {
    const content = {
      title: 'Inside React Project',
      content: 'We are inside React Project',
    }
    return await createPost(content);
  }
  
  const fetchAllPostsButton = async () => {
    return await fetchAllPosts();
  }
  const fetchSinglePostsButton = async () => {
    const idFromMongo = "6810207b25386f9dc7c88ebf";
    return await fetchSinglePost(idFromMongo);
  }
  const updatePostsButton = async () => {
    const idFromMongo = "6810207b25386f9dc7c88ebf";
    const content = {
      title: 'UPDATED!!! Inside React Project',
      content: 'UPDATEDD!!! We are inside React Project',
    }
    return await updatePost(content, idFromMongo);
  }
  const deletePostButton = async () => {
    const idFromMongo = "6810207b25386f9dc7c88ebf";
    return await deletePost(idFromMongo);
  }
  return (
    <>
      <h1>Welcome to Home page</h1>
      <button onClick={createPostButton}>Create Post</button>
      <button onClick={fetchAllPostsButton}>Fetch all Posts</button>
      <button onClick={fetchSinglePostsButton}>Fetch Single Post</button>
      <button onClick={updatePostsButton}>Update Post</button>
      <button onClick={deletePostButton}>Delete Post</button>

    </>
  );
}

export default Home;