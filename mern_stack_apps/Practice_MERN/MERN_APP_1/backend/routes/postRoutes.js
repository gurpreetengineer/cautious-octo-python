const express = require('express');
const {
  createPostControler, 
  readAllPostsController,
  readOnePostController,
  updatePostController,
  deletePostController
} = require('../controllers/post');

const router = express.Router();

const {
  createPostAPI,
  getAllPostsAPI,
  getPostByIdAPI,
  updatePostAPI,
  deletePostAPI,
} = process.env;

router.post(createPostAPI, createPostControler);
router.post(getPostByIdAPI, readOnePostController);
router.post(updatePostAPI, updatePostController);
router.get(getAllPostsAPI, readAllPostsController);
router.delete(deletePostAPI, deletePostController);

module.exports = router;
