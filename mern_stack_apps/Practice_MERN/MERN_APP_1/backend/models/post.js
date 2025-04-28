const mongoose = require('mongoose');

const postSchema = new mongoose.Schema({
  title: { type: String, required: true, minlength: 1 },
  content: {type: String, required: true, minlength: 1 },
  date: { type: Date, default: Date.now }
});

// Define the blog post model
const Post = mongoose.model('Post', postSchema); //by default, mongodb will make it lowercase + plural
// const Post = mongoose.model('Post', userSchema, 'CustomCollectionName'); //for custom collection name in mongodb


module.exports = Post;
