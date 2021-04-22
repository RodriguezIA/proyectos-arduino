const http = require('http');
const express = require('express');
const socketIO = require('socket.io');
const app = express();
const server = http.createServer(app);
const io = socketIO.listen(server);

app.use(express.static(__dirname + '/public'));

server.listen(3000, function (){
    console.log('server listening on port', 3000);
});

//serial comunication
const Serialport = require('serialport');
const Readline = Serialport.parsers.Readline;

const port = new Serialport('COM3', {baudRate: 9600});

const parser = port.pipe(new Readline({
    delimiter: '\r\n'
}));

parser.on('open', function(){
    console.log('connection is opened');
});

parser.on('data', function(vector) {
    let lum = parseInt(vector[0], 10) + " lum";
    console.log(lum);
    io.emit('lumens', vector[0]);
});

port.on('error', function (err) {
    console.log(err);
});