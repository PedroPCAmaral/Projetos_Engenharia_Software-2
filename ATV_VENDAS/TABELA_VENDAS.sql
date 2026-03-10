create database vendas_120;
use vendas_120;

CREATE TABLE venda (
idvenda INT AUTO_INCREMENT PRIMARY KEY,
data DATE NOT NULL,
produto VARCHAR(50) NOT NULL,
quantidade INT NOT NULL,
valorunitario DECIMAL(10,2) NOT NULL
);

show tables;

select *from venda;