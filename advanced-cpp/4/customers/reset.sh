docker ps -a
docker stop customers
docker rm customers
docker volume ls
docker volume prune

docker run --name customers -p 5430:5432 -e POSTGRES_PASSWORD=mysecretpassword -v customers_data:/var/lib/postgresql/data -d postgres

cat src/seed.sql | docker exec -i customers psql -U postgres