let express = require('express');
let app = express();
app.set('views', './views');
app.set('view engine', 'pug');
app.locals.pretty = true;

app.use(express.static('public'));
// /topic으로 들어온 uri에 /topic/0 과 같이 들어왔을 때 topic_id에 0이 들어가며
// req객체의 params객체에 :으로 받은 변수명으로 들어가게 된다.
app.get('/topic/:topic_id/', function (req, res) {
    let topics = [
        'javascript is...',
        'Node js is...',
        'Express is...'
    ];
    let output = `
    <a href="/topic?id=0">JavaScript</a><br>
    <a href="/topic?id=0">Nodejs</a><br>
    <a href="/topic?id=0">Express</a><br>
    ${topics[req.params.topic_id]}
    `
    res.send(output);
})
// /topic/1/edit 처럼 추가적으로 params를 받을 수 있다.
app.get('/topic/:id/:mode', function (req, res) {
    res.send(req.params.id + ',' + req.params.mode)
})

app.listen(3000, function () {
    console.log('connected 3000port!');
});

app.get('/', function (req, res) {
    res.send('Hello home page');
})