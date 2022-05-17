const db = require('../database');

const car = {
    getById: function(id, callback) {
        return db.query('select * from car where id=?', [id], callback);
    },
    getAll: function(callback) {
        return db.query('select * from car', callback);
    },
    add: function(car, callback) {
        return db.query(
            'insert into car (branch,model) values (?,?)',
            [car.branch, car.model],
            callback
        );
    },
    delete: function(id, callback) {
        return db.query('delete from car where id=?', [id], callback);
    },
    update: function(id, car, callback) {
        return db.query(
            'update car set branch=?, model=? where id=?',
            [car.branch, car.model, id],
            callback
        );
    }
};
module.exports = car;