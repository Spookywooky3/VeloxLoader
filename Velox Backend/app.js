'use strict';
const express = require('express');
const logger = require('morgan');
const mongoose = require('mongoose');
const bcrypt = require('bcrypt');

/*
 * TODO:
 * Seperate routes, mongo model into different files
 * Maybe even add some security features l0l
 * Add UI for admins to add users ( Seperate web app maybe? So it doesnt get so spaghetti )
 */

// mongodb connection string, change to whatever your db is
mongoose.connect('mongodb://localhost:27017/user_db', { useNewUrlParser: true, useUnifiedTopology: true });

// Define user schema and model
var userSchema = mongoose.Schema({ username: String, password: String });
var User = mongoose.model('User', userSchema, 'users');

// database event handlers
var database = mongoose.connection;
database.on('error', () => console.error('MongoDB Connection Error'));
database.once('open', () => console.log('MongoDB Connected'));

var app = express();
app.use(logger('short'));

// routes
app.get('/auth', function (req, res) {
    User.findOne({ username: req.query.username }, function (error, obj) {
        if (obj == null) {
            res.send('0');
            return;
        }
            
        // Kind of pointless rn but its for the future when i expand on this junk
        bcrypt.compare(req.query.password, obj.password, (error, result) => {
            if (result == true)
                res.send('1');
            else
                res.send('0');
        });
    });
});

// Comment this out for now so people can't just add accounts, was just for testing
/* 
app.get('/useradd', function (req, res) {
    // Generate salt with 10 rounds
    bcrypt.genSalt(10, (error, salt) => {
        // Hash password
        bcrypt.hash(req.query.password, salt, (error, hash) => {
            // Create new user
            var newUser = new User({ username: req.query.username, password: hash });
            // Save user to collection
            newUser.save(function (error, user) { console.log(user.username + " saved to collection."); });
        });
    });
    res.end();
});
*/

// listen on specified port
app.set('port', process.env.PORT || 8080);
var server = app.listen(app.get('port'), function () { console.log('Velox Running...') });