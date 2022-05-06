const express = require('express'),
  app = express(),
  mysql = require('mysql2'),
  cors = require('cors'),
  bodyParser = require('body-parser');


db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'car_db'
})


// make server object that contain port property and the value for our server.
var server = {
  port: 4040
};

// routes
const cars = require('./routes/car');

// use the modules
app.use(cors());
app.use(bodyParser.urlencoded({ extended: false }))

app.use('/car', cars);

// starting the server
app.listen( server.port , () => console.log(`Server started, listening port: ${server.port}`));

