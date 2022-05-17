const mysql = require('mysql');
const connection = mysql.createPool({
    host: 'localhost',
    user: 'testiuser',
    password: 'testpass',
    database: 'testidb'
});
module.exports = connection;