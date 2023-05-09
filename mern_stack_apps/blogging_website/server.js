const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');

// Create the Express app
const app = express();

// Set up the database connection
mongoose.connect('mongodb://localhost/blog', {
  useNewUrlParser: true,
  useUnifiedTopology: true
}).then(() => {
  console.log("Database connection successful");
}).catch((err) => {
  console.log("Database connection error", err);
});

// Define the blog post schema
const postSchema = new mongoose.Schema({
  title: String,
  content: String,
  date: { type: Date, default: Date.now }
});

// Define the blog post model
const Post = mongoose.model('Post', postSchema);

// Configure the body-parser middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// Define the API routes

// Create a new blog post
app.post('/api/posts', (req, res) => {
  const post = new Post({
    title: req.body.title,
    content: req.body.content
  });
  post.save((err, post) => {
    if (err) {
      console.log(err);
      res.status(500).send("Server error");
    } else {
      res.status(201).json(post);
    }
  });
});

// Retrieve all blog posts
app.get('/api/posts', (req, res) => {
  Post.find((err, posts) => {
    if (err) {
      console.log(err);
      res.status(500).send("Server error");
    } else {
      res.status(200).json(posts);
    }
  });
});

// Retrieve a single blog post by ID
app.get('/api/posts/:id', (req, res) => {
  Post.findById(req.params.id, (err, post) => {
    if (err) {
      console.log(err);
      res.status(500).send("Server error");
    } else if (!post) {
      res.status(404).send("Post not found");
    } else {
      res.status(200).json(post);
    }
  });
});

// Update a blog post
app.put('/api/posts/:id', (req, res) => {
  Post.findByIdAndUpdate(req.params.id, {
    title: req.body.title,
    content: req.body.content
  }, { new: true }, (err, post) => {
    if (err) {
      console.log(err);
      res.status(500).send("Server error");
    } else if (!post) {
      res.status(404).send("Post not found");
    } else {
      res.status(200).json(post);
    }
  });
});

// Delete a blog post
app.delete('/api/posts/:id', (req, res) => {
  Post.findByIdAndDelete(req.params.id, (err, post) => {
    if (err) {
      console.log(err);
      res.status(500).send("Server error");
    } else if (!post) {
      res.status(404).send("Post not found");
    } else {
      res.status(204).send();
    }
  });
});

// Start the server
app.listen(3000, () => {
  console.log('Server started on port 3000');
});
