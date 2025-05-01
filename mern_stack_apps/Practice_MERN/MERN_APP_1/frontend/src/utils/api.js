import axios from 'axios';

const initialRoute = '//localhost:3000/api';

export const createPost = async (content) => {
  const apiRoute = `${initialRoute}/posts`;
  let returnVar;

  await axios.post(apiRoute, content).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar', returnVar);
  return returnVar;
};

export const updatePost = async (newContent, postId) => {
  const apiRoute = `${initialRoute}/updateById/post?id=${postId}`;
  let returnVar;

  await axios.post(apiRoute, newContent).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar', returnVar);
  return returnVar;
}

export const fetchAllPosts = async () => {
  const apiRoute = `${initialRoute}/getAll/posts`;
  let returnVar;

  await axios.get(apiRoute).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar', returnVar);
  return returnVar;
}

export const fetchSinglePost = async postId => {
  const apiRoute = `${initialRoute}/getById/post?id=${postId}`;
  let returnVar;

  await axios.post(apiRoute).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar', returnVar);
  return returnVar;
}

export const deletePost = async postId => {
  const apiRoute = `${initialRoute}/deleteById/post?id=${postId}`;
  let returnVar;

  await axios.delete(apiRoute).then((response) => {
    returnVar = response;
    return;
  }).catch(exception => {
    returnVar = exception;
    return;
  })
  console.log('returnVar', returnVar);
  return returnVar;
}
