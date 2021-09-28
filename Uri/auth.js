let auth = (req, res, next) => {
    console.log('Authinticate...');
    next();
}

module.exports = auth;