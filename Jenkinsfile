pipeline {
    options {timestamps()}

    agent none
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
                cmakeBuild(installation: 'InSearchPath')
                echo "Build completed"
            }
        }
       
        stage ("Test") {
            agent {docker {image 'alpine' args '-u=\"root\"'}}
            steps {
                sh 'mkdir build'
                sh 'cd build'
                sh 'cmake -G"Visual Studio 14 2015 Win64" ..'
                sh 'cmake --build . '
            }
        }
    }
}