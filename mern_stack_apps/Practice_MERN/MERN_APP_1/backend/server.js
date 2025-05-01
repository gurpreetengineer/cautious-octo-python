require('dotenv').config();

const express = require('express');
const mongoose = require('mongoose')
const bodyParser = require('body-parser');
const cors = require('cors');

const globalErrorHandlingMiddleware = require('./middlewares/globalErrorHandlingMiddleware')

const postRoutes = require('./routes/postRoutes')

const {
  createPostAPI,
  getAllPostsAPI,
  MONGO_URI,
  PORT
} = process.env;

const app = express();

mongoose.connect(MONGO_URI, {
  useNewUrlParser: true,
  useUnifiedTopology: true
}).then(() => {
  console.log('Database connection successful');
}).catch(err => {
  console.log("Database connection error", err);
});

// Configure the body-parser middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.json());
app.use(cors());

app.use(globalErrorHandlingMiddleware);

app.use('/', postRoutes);

app.listen(PORT, () => {
  console.log('Server started on port 3000');
})

