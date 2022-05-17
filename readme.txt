// MySQL DB Creation

CREATE DATABASE testidb;
CREATE USER 'testiuser'@'localhost' IDENTIFIED WITH mysql_native_password BY 'testpass';
GRANT ALL on testidb.* to 'testiuser'@'localhost';


USE testidb;

CREATE TABLE book(
id_book INT primary key auto_increment,
name VARCHAR(255),
author VARCHAR(255),
isbn VARCHAR(20)
);

INSERT INTO book(name,author,isbn) VALUES('PHP Basic','Bob Jones','123-456-789-111-x');
INSERT INTO book(name,author,isbn) VALUES('Statistics','Lisa Smith','222-333-444-555-y');


CREATE TABLE car(
id INT primary key auto_increment,
branch VARCHAR(255),
model  VARCHAR(255)
);

INSERT INTO car(branch,model) VALUES ('Valmet Automotive', 'Saab 95');
INSERT INTO car(branch,model) VALUES ('Toyota', 'Corolla E120');