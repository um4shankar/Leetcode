WITH Categories AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
),
CTE AS (
    SELECT
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income <= 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category
    FROM Accounts
)
SELECT
    C.category,
    COUNT(T.category) AS accounts_count
FROM Categories C
LEFT JOIN CTE T
ON C.category = T.category
GROUP BY C.category;