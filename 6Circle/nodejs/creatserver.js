const http = require('http');

const hostname = '127.0.0.1';
const port = 1337;

let server = http.createServer(function(req, res){
    
});
server.listen(port, hostname, function(){
    console.log(`server running at http://${hostname}:${port}/`);

})