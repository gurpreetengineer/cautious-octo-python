import axios from 'axios';

const initialRoute = `localhost:3000/api`;

export const createPost = (content) => {
  const apiRoute = `${initialRoute}/posts`;
  let returnVar;

  axios.post(apiRoute, content).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar');
  return returnVar;
};

export const updatePost = (newContent, postId) => {
  const apiRoute = `${initialRoute}/updateById/post?id=${postId}`;
  let returnVar;

  axios.post(apiRoute, newContent).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar');
  return returnVar;
}

export const fetchAllPosts = () => {
  const apiRoute = `${initialRoute}/getAll/posts`;
  let returnVar;

  axios.get(apiRoute).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar');
  return returnVar;
}

export const fetchSinglePost = postId => {
  const apiRoute = `${initialRoute}/getById/post?id=${postId}`;
  let returnVar;

  axios.post(apiRoute).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar');
  return returnVar;
}

export const deletePost = postId => {
  const apiRoute = `${initialRoute}/deleteById/post?id=${postId}`;
  let returnVar;

  axios.post(apiRoute).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar');
  return returnVar;
}