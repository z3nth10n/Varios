"use strict";

process.title = "chessNodeJS";

var http = require('http'),
    fs = require('fs'),
    index = fs.readFileSync(__dirname + '/index.html');

var pieces = [];

for(var i=0; i<32; i++)
	pieces.push({top: "0px", left: "0px"});
	
var app = http.createServer(function(req, res) {
	console.log("Client");
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(index);
});

app.on('error', function (e) {
  console.log("Error: " + e.code);
});

var io = require('socket.io').listen(app);

io.on('connection', function(socket) {
    socket.on("movePiece", function(e){
		if(typeof e.id == 'undefined' || typeof e.top == 'undefined' || typeof e.left == 'undefined')
			return;
		if(e.top.substring(e.top.length-2) != "px" || e.left.substring(e.left.length-2) != "px" || parseInt(e.id)<0 || parseInt(e.id)>=32)
			return;
		pieces[parseInt(e.id)].top = parseInt(e.top.substring(0,e.top.length-2))+"px";
		pieces[parseInt(e.id)].left = parseInt(e.left.substring(0,e.left.length-2))+"px";
		socket.broadcast.emit("movePiece", e);
	});
	socket.on("getAllPieces", function(e){
		
		for(var i=0; i<32; i++)
			socket.emit("movePiece", {id: i,
									  top: pieces[i].top,
									  left: pieces[i].left});
	});
	console.log("Client connected from: " + socket.request.connection.remoteAddress);
});

app.listen(8080);
console.log("Listening...");
