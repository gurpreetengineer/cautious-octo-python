
// Global Error Handling Middleware for JSON Parsing Errors

const globalErrorHandlingMiddleware = (err, req, res, next) => {
  if (err instanceof SyntaxError && err.status== 400 && 'body' in err) {
    console.log('BAD JSON Error: ', err.message);

    return res.status(400).json({
      success: false,
      message: 'Invalid JSON payload passed.'
    })
  }

  next(); // If not a syntax error, pass to default error handler
}

module.exports = globalErrorHandlingMiddleware;