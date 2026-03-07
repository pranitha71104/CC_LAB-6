stage('Deploy Backends') {
    steps {
        sh '''
        docker network create lab6-net || true
        docker rm -f backend1 backend2 || true
        docker run -d --name backend1 --network lab6-net backend-app
        docker run -d --name backend2 --network lab6-net backend-app
        '''
    }
}

stage('Deploy NGINX Load Balancer') {
    steps {
        sh '''
        docker rm -f nginx-lb || true

        docker run -d --name nginx-lb -p 80:80 --network lab6-net nginx

        docker cp nginx/default.conf nginx-lb:/etc/nginx/conf.d/default.conf

        docker exec nginx-lb nginx -s reload
        '''
    }
}
