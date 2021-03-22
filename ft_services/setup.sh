# kubectl delete deploy --all
# kubectl delete service --all
# kubectl delete pvc --all
# kubectl delete pv --all
kubectl delete -f srcs/nginx/nginx.yaml
kubectl delete -f srcs/ftps/ftps.yaml
kubectl delete -f srcs/mysql/mysql.yaml
kubectl delete -f srcs/wordpress/wordpress.yaml
kubectl delete -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl delete -f srcs/grafana/grafana.yaml
kubectl delete -f srcs/influxdb/influxdb.yaml
# # minikube stop
minikube delete
minikube delete
minikube start
minikube dashboard &
minikube addons enable metallb
kubectl apply -f ./srcs/configmap.yaml
eval $(minikube docker-env);
docker build -t nginx_image ./srcs/nginx
docker build -t ftps_image ./srcs/ftps
docker build -t mysql_image ./srcs/mysql
docker build -t wordpress_image ./srcs/wordpress
docker build -t phpmyadmin_image ./srcs/phpmyadmin
docker build -t grafana_image ./srcs/grafana
docker build -t influxdb_image ./srcs/influxdb
kubectl apply -f ./srcs/nginx/nginx.yaml
kubectl apply -f ./srcs/ftps/ftps.yaml
kubectl apply -f ./srcs/mysql/mysql.yaml
kubectl apply -f ./srcs/wordpress/wordpress.yaml
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f ./srcs/grafana/grafana.yaml
kubectl apply -f ./srcs/influxdb/influxdb.yaml