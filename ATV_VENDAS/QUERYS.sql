-- 1. projetar todas as vendas --
SELECT * FROM venda;

-- 2. projetar todos os produtos e seus valores --
SELECT produto, valorunitario FROM venda;

-- 3. quantidade de produtos cadastrado --
SELECT produto, valorunitario FROM venda;

-- 4. Valor a pagar se valorunitario sofrer um acréscimo de 10% -- 
SELECT produto, valorunitario, valorunitario * 1.10 AS valor_com_acrescimo
FROM venda;

-- 5. qual o valor a pagar se comprarmos todos os produtos do primeiro registro --
SELECT quantidade * valorunitario AS valor_total
FROM venda
WHERE idvenda = 1;

-- 6. total das vendas por produto --
SELECT produto, SUM(quantidade * valorunitario) AS total_vendas
FROM venda
GROUP BY produto;

-- 7. quantidade total vendido por produto --
SELECT produto, SUM(quantidade) AS total_vendido
FROM venda
GROUP BY produto;

-- 8. Numero de vendas por dia --
SELECT data, COUNT(*) AS numero_vendas
FROM venda
GROUP BY data;

-- 9. valor medio das vendas por produto --
SELECT produto, AVG(valorunitario) AS media_valor
FROM venda
GROUP BY produto;

-- 10. filtrar vendas com valorunitario acima de um certo limite --
SELECT * FROM venda
WHERE valorunitario > 500;

-- 11.vendas dentro de um intervalo de datas --
SELECT * FROM venda
WHERE data BETWEEN '2026-03-02' AND '2026-03-05';

-- 12. produto e o valor mais caro --
SELECT produto, valorunitario
FROM venda
ORDER BY valorunitario DESC
LIMIT 1;

-- 13. produto e o valor mais baixo --
SELECT produto, valorunitario
FROM venda
ORDER BY valorunitario ASC
LIMIT 1;




