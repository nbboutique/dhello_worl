pipeline {
    options {timestamps()}

    agent any
    
	parameters {
		booleanParam name: 'RUN_TESTS', defaultValue: true, description: 'Run Tests?'
		booleanParam name: 'RUN_ANALYSIS', defaultValue: true, description: 'Run Static Code Analysis?'
		booleanParam name: 'DEPLOY', defaultValue: true, description: 'Deploy Artifacts?'
	}
    stages {
        stage("Check scm") {
            agent any
            steps {
                checkout scm
            }
        }
        stage("Build") {
            steps {
                cmake arguments: 
                '-DCMAKE_TOOLCHAIN_FILE=~/Projects/vcpkg/scripts/buildsystems/vcpkg.cmake', 
                                       installation: 'InSearchPath'
                cmakeBuild buildType: 'Release', cleanBuild: true, 
                                       installation: 'InSearchPath', steps: [[withCmake: true]]
            }
            steps {
                echo "Building... ${BUILD_NUMBER}"
                echo "Build completed"
            }
        }
       
        stage ("Test") {
            
            when {
                environment name: 'RUN_TESTS', value: 'true'
            }
            steps {
                ctest 'InSearchPath'
            }
        }
    }
}