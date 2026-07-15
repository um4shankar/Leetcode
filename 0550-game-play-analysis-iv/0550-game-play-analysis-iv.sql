WITH CTE AS (
    SELECT player_id, MIN(event_date) AS first_day
    FROM Activity
    GROUP BY player_id
)
SELECT
    ROUND(
        COUNT(DISTINCT CASE
            WHEN DATEDIFF(A.event_date, CTE.first_day) = 1
            THEN A.player_id
        END)
        /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM Activity A
JOIN CTE
ON A.player_id = CTE.player_id;