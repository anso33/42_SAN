#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

echo "env[MARIADB_HOST] = \$MARIADB_HOST" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_ADMIN_USER] = \$MARIADB_ADMIN_USER" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_ADMIN_PASSWORD] = \$MARIADB_ADMIN_PASSWORD" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_DATABASE] = \$MARIADB_DATABASE" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "listen = 0.0.0.0:9000" >> /etc/php/7.3/fpm/pool.d/www.conf

chown -R :www-data /var/www/html

wp core download --path=/var/www/html --locale=ko_KR --allow-root
wp config create --dbname=$MARIADB_DATABASE --dbuser=$MARIADB_USER --dbpass=$MARIADB_PASSWORD --dbhost=$MARIADB_HOST --dbcharset="utf8" --allow-root
wp core install --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --path=/var/www/html --allow-root
wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PASSWORD --allow-root
wp plugin update --all --allow-root

exec php-fpm7.3 -R -F
