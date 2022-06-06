let express = require('express');
let app = express();

app.locals.pretty = true;

app.set('views', './views');
app.set('view engine', 'pug');
app.use(express.static('public'));
app.get('/topic', function (req, res) {
    res.send(req.query.id + ',' + req.query.name);
})
app.get('/template', function (req, res) {
    res.render('temp', { time: Date(), titleee: 'pug' }); //template file을 읽어 오는 함수
})
app.get('/', function (req, res) {
    res.send('Hello home page');
}); //GET 방식으로 웹서버에 요청
app.get('/dynamic', function (req, res) {
    let lis = '';
    for (let i = 0; i < 5; i++) {
        lis = lis + '<li>coding</li>';
    }
    let time = Date();
    let output = `
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta http-equiv="X-UA-Compatible" content="ie=edge">
        <title>Document</title>
    </head>
    <body>
        Hello, Dynamic!
        <ul>
        ${lis}
        </ul>
        ${time}
    </body>
    </html>`;
    res.send(output);
})
app.get('/route', function (req, res) {
    res.send('Hello Router, <img src="/route.png">')
})
app.get('/login', function (req, res) {
    res.send('login please');
})
app.listen(3000, function () {
    console.log('connected 3000port!');
});