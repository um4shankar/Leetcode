WITH CTE1 AS (
    SELECT visited_on, SUM(amount) AS daily_amount
    FROM Customer
    GROUP BY visited_on
),
CTE2 AS (
    SELECT
        visited_on,
        daily_amount,
        ROW_NUMBER() OVER (ORDER BY visited_on) AS rn,
        SUM(daily_amount) OVER (
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        ROUND(
            AVG(daily_amount) OVER (
                ORDER BY visited_on
                ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
            ),
            2
        ) AS average_amount
    FROM CTE1
)

SELECT
    visited_on,
    amount,
    average_amount
FROM CTE2
WHERE rn > 6;