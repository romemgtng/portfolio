SELECT movies.title, ratings.rating
FROM ratings
INNER JOIN movies ON ratings.movie_id=movies.id
WHERE movies.year='2010' and ratings.rating IS NOT NULL
ORDER BY rating DESC, title;