WITH CTE AS (
    SELECT pid, tiv_2015, tiv_2016, CONCAT(lat, '-', lon) AS loc
    FROM Insurance
),

CTE2 AS (
    SELECT *
    FROM CTE
    WHERE loc IN (
        SELECT loc
        FROM CTE
        GROUP BY loc
        HAVING COUNT(*) = 1
    )
),

CTE3 AS (
    SELECT *
    FROM CTE2
    WHERE tiv_2015 IN (
        SELECT tiv_2015
        FROM CTE
        GROUP BY tiv_2015
        HAVING COUNT(*) > 1
    )
)

SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM CTE3;