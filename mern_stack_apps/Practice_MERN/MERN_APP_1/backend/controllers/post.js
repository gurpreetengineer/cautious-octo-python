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

const readAllPostsController = async (req, res) => {
  try {
    const allPosts = await Post.find({});

    res.status(200).json({
      status: 'ok',
      fetching: 'successful',
      areAllFetched: true,
      allPosts: allPosts,
    })
  } catch (exception) {
    res.status(400).send({
      status: 'not ok',
      fetching: 'failed',
      areAllFetched: false,
      error: {
        label: exception?.name,
        message: exception?.message,
      }
    })
  }
}

const readOnePostController = async (req, res) => {
  try {
    const postFetched = await Post.findById(req.query.id);
    if (!postFetched) {
      return res.status(200).json({
        status: 'ok',
        fetching: 'failed',
        isPostFound: false,
        message: 'Post not found',
      })
    }
    res.status(200).json({
      status: 'ok',
      fetching: 'successful',
      isPostFound: true,
      postFetched: postFetched,
    })
  } catch (exception) {
    res.status(400).send({
      status: 'not ok',
      fetching: 'failed',
      isPostFetched: false,
      error: {
        label: exception?.name,
        message: exception?.message,
      }
    })
  }
}

const updatePostController = async (req, res) => {
  try {
    console.log("req.body", req.body)
    if (!req.body || Object.keys(req.body).length === 0 || !req.body?.title || !req.body?.content) {
      return res.status(400).json({
        status: 'not ok',
        updation: 'failed',
        isPostUpdated: false,
        message: 'Body is required.',
      })
    }
    const updatedPost = await Post.findByIdAndUpdate(req.query.id, req.body, {
      new: true,
      runValidators: true
    });
    if (!updatedPost) {
      return res.status(200).json({
        status: 'ok',
        updation: 'failed',
        isPostUpdated: false,
        message: 'Post not found',
      })
    }
    res.status(200).json({
      status: 'ok',
      updation: 'successful',
      isPostUpdated: true,
      updatedPost: updatedPost,
    })
  } catch (exception) {
    res.status(400).send({
      status: 'not ok',
      updation: 'failed',
      isPostUpdated: false,
      error: {
        label: exception?.name,
        message: exception?.message,
      }
    })
  }
}
const deletePostController = async (req, res) => {
  try {
    // const deletedPost = await findByIdAndDelete(req.query.id);
    const deletedPost = await Post.findByIdAndDelete(req.query.id);
    if (!deletedPost) {
      return res.status(200).json({
        status: 'ok',
        deletion: 'failed',
        isPostDeleted: false,
        message: 'Post not found',
      })
    }
    res.status(200).json({
      status: 'ok',
      deletion: 'successful',
      isPostDeleted: true,
      deletedPost: deletedPost,
    })
  } catch (exception) {
    res.status(400).send({
      status: 'not ok',
      deletion: 'failed',
      isPostDeleted: false,
      error: {
        label: exception?.name,
        message: exception?.message,
      }
    })
  }

}

// module.exports.createPostControler = createPostControler;
// module.exports.readAllPostsController = readAllPostsController;
module.exports = {
  createPostControler: createPostControler,
  readOnePostController: readOnePostController,
  updatePostController: updatePostController,
  readAllPostsController: readAllPostsController,
  deletePostController: deletePostController,
};