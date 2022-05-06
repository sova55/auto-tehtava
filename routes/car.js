const { append } = require('vary');

const express = require('express'),
    router = express.Router();


// list all
router.get('/cars', function(req, res) {
    let sql = `SELECT * FROM car`;
    db.query(sql, function(err, data, fields) {
        if (err) throw err;
        res.json({
            status: 200,
            data,
            message: "Car list retrieved successfully"
        })
    })
});

// get car by Id

router.get('/cars/:id', function (req,res) {

    db.query('select * from car where ID=?', + req.params.id, function (err,data, fields ) {
        if (err) throw err;
        res.json({
            status: 200,
            data,
            message: "Car ID retrieved successfully"
        })
    })
})




// delete user by ID
router.post('/delete/:id', function (req,res, next) {

    
    db.query('DELETE FROM car WHERE id = ' + req.params.id, function (err,data, fields) {
        if (err) throw err;
        res.json({
            status: 200,
            message: "User deleted successfully"
        })
    })


})




// update car 

router.post('/edit/:id', function (req,res, next) {

    var carData = {
        branch: req.body.branch,
        model: req.body.model
    }

    db.query('UPDATE car SET ? WHERE id = ' + req.params.id, carData,  function (err) {
        if (err) throw err;
        res.json({
            status:200,
            message: "Car edited successfully"
        })
    })
});



//create new car

router.post('/new', function(req,res) {
    let sql = `INSERT INTO car(branch, model) VALUES (?)`;

    let values = [
        req.body.branch,
        req.body.model
    ];

    db.query(sql, [values], function(err,data, fields) {
        if (err) throw err;
        res.json({
            status: 200,
            values,
            
            message: "New car added successfully"
        })
    })
});



module.exports = router;