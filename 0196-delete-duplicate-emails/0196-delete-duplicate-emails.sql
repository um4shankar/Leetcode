WITH CTE AS (
    SELECT
        id,
        ROW_NUMBER() OVER (PARTITION BY email ORDER BY id) AS rn
    FROM Person
)
DELETE P
FROM Person P
JOIN CTE C
ON P.id = C.id
WHERE C.rn > 1;