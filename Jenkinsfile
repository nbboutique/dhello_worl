pipeline {
    options {timestamps()}

    agent any
    stages {
        stage("Check scm") {
            agent any
            steps {
                checkout scm
            }
        }
        stage("Build") {
            steps {
                echo "Building... ${BUILD_NUMBER}"
                echo "Build completed"
            }
        }
       
        stage ("Test") {
            
            steps {

            }
        }
    }
}
