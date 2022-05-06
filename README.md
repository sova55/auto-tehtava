# auto-tehtava

//DB creation

CREATE DATABASE car_db;
USE car_db;

CREATE TABLE car(
id INT primary key auto_increment,
branch VARCHAR(255),
model  VARCHAR(255)
);
