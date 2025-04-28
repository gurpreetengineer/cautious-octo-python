const Post = require('../models/post');

const createPostControler = async (req, res) => {
  try {
    const { title, content } = req.body;
    const postBody = {
      title,
      content,
    };
    const postResponse = await Post.create(postBody);
    res.status(200).send({
      status: 'ok',
      creation: 'successful',
      postCreatedStatus: false,
      postCreated: postResponse,
    })
  } catch (exception) {
    res.status(400).send({
      status: 'not ok',
      creation: 'failed',
      postCreatedStatus: false,
      error: {
        label: exception?.name,
        message: exception?.message,
      }
    })
  }

};

module.exports = createPostControler;