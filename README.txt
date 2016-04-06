cf create-service DTO-staging-RDS-mysql 5.6-t2.micro-5G gov-au-authoring-db

cf push -i 1 -u none -c "./vendor/bin/drush sql-drop"