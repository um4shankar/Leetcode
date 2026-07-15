SELECT
    P.product_id,
    CASE
        WHEN SUM(US.units) IS NULL THEN 0
        ELSE ROUND(SUM(P.price * US.units) / SUM(US.units), 2)
    END AS average_price
FROM Prices P
LEFT JOIN UnitsSold US
ON P.product_id = US.product_id
AND US.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY P.product_id;