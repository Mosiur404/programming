const config = require('config');
const debug = require('debug')('app:startup');
const express = require('express');
const helmet = require('helmet');
const morgan = require('morgan');
const logger = require('./logger');
const auth = require('./auth');
const app = express();
const port = process.env.port || 3000;

app.set('view engine', 'pug');

app.use(express.json());
app.use(helmet());
app.use(logger);
app.use(auth);
if (app.get('env') === 'development') {
    app.use(morgan('tiny'));
}

debug('App config' + config.get('mail.password'));

let courses = [
    { id: 1, name: "course 1" },
    { id: 2, name: "course 2" },
    { id: 3, name: "course 3" },
]

app.get('/', (req, res) => {
    res.render('index', { title: 'My App', message: 'Hello World' });
});
app.get('/api/courses', (req, res) => {
    res.send(courses);
});

app.get('/api/courses/:id', (req, res) => {
    const course = courses.find((c) => { return c.id === parseInt(req.params.id) });
    if (!course) res.status(404).send('not found');
    res.send(course);
});

app.post('/api/courses', (req, res) => {
    if (!req.body.name || req.body.name.length < 3)
        res.status('404').send('error name');
    const course = {
        id: courses.length + 1,
        name: req.body.name
    };
    courses.push(course);
    res.send(courses);
});









app.listen(port, () => console.log(`listening on ${port}`))