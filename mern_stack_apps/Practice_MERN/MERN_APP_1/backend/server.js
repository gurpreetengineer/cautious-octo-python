const express = require('express');
const mongoose = require('mongoose')
const bodyParser = require('body-parser');

const createPostControler = require('./controllers/post')

const globalErrorHandlingMiddleware = require('./middlewares/globalErrorHandlingMiddleware')

require('dotenv').config()

const {
  createPostAPI,
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

app.use(globalErrorHandlingMiddleware);

app.post(createPostAPI, createPostControler);

app.listen(PORT, () => {
  console.log('Server started on port 3000');
})

