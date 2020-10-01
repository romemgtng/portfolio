SELECT people.name
FROM stars
INNER JOIN people ON people.id=stars.person_id
INNER JOIN movies on movies.id=stars.movie_id
WHERE movies.year='2004'
ORDER BY people.birth