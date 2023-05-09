const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const { CleanWebpackPlugin } = require('clean-webpack-plugin');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');

const isDevelopment = process.env.NODE_ENV !== 'production';

module.exports = {
  mode: isDevelopment ? 'development' : 'production',
  entry: './src/index.js',
  output: {
    filename: isDevelopment ? '[name].js' : '[name].[contenthash].js',
    path: path.resolve(__dirname, 'dist'),
    publicPath: '/',
  },
  devtool: isDevelopment ? 'eval-source-map' : 'source-map',
  devServer: {
    contentBase: path.join(__dirname, 'dist'),
    compress: true,
    port: 3000,
    historyApiFallback: true,
  },
  resolve: {
    extensions: ['.js', '.jsx'],
  },
  module: {
    rules: [
      {
        test: /\.(js|jsx)$/,
        exclude: /node_modules/,
        use: {
          loader: 'babel-loader',
        },
      },
      {
        test: /\.css$/,
        use: [
          isDevelopment ? 'style-loader' : MiniCssExtractPlugin.loader,
          'css-loader',
          'postcss-loader',
        ],
      },
      {
        test: /\.(png|svg|jpg|jpeg|gif)$/i,
        type: 'asset/resource',
      },
      {
        test: /\.(woff|woff2|eot|ttf|otf)$/i,
        type: 'asset/resource',
      },
    ],
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: './public/index.html',
    }),
    new CleanWebpackPlugin(),
    new MiniCssExtractPlugin({
      filename: isDevelopment ? '[name].css' : '[name].[contenthash].css',
    }),
  ],
};
// This configuration file sets the entry point of the application to ./src/index.js and the output directory to ./dist. It also sets up the devServer to run on port 3000 with history API fallback for React Router.

// Webpack is configured to handle JavaScript and JSX files with Babel loader, CSS files with CSS loader and PostCSS loader, and image and font files with asset/resource loader. The HtmlWebpackPlugin is used to generate a index.html file with the template set to ./public/index.html. The CleanWebpackPlugin is used to clean the dist folder before generating new files. Finally, the MiniCssExtractPlugin is used to extract the CSS code into a separate file.

// Note that you may need to adjust the test values in the module.rules section to match the specific file types and loaders that you want to use in your project.

