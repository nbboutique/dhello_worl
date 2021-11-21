pipeline {
	agent any


	parameters {
		booleanParam name: 'RUN_TESTS', defaultValue: true, description: 'Run Tests?'
		booleanParam name: 'RUN_ANALYSIS', defaultValue: true, description: 'Run Static Code Analysis?'
		booleanParam name: 'DEPLOY', defaultValue: true, description: 'Deploy Artifacts?'
	}

	stages {
        stage('Build') {
		agent {
                docker {
                    image 'lab4-jenkins:1'
                    // Run the container on the node specified at the top-level of the Pipeline, in the same workspace, rather than on a new node entirely:
                    reuseNode true
                }
            }
            steps {
		    echo "Building... ${BUILD_NUMBER}"
                echo "Build completed"
// 		sh cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - Unix Makefiles" /home/admin-local/Desktop/hello_world
// 		cmake --build /home/admin-local/Desktop/hello_world/cmake-build-debug --target hello_world -- -j 1
//                 cmake arguments: '-DCMAKE_TOOLCHAIN_FILE=~/Projects/vcpkg/scripts/buildsystems/vcpkg.cmake', installation: 'InSearchPath'
//                 cmakeBuild buildType: 'Release', cleanBuild: true, installation: 'InSearchPath', steps: [[withCmake: true]]
		    
            }
        }

//         stage('Test') {
//             when {
//                 environment name: 'RUN_TESTS', value: 'true'
//             }
//             steps {
//                 hello_world 'InSearchPath'
//             }
//         }

//         stage('Analyse') {
//             when {
//                 environment name: 'RUN_ANALYSIS', value: 'true'
//             }
//             steps {
//                 sh label: '', returnStatus: true, script: 'cppcheck . --xml --language=c++ --suppressions-list=suppressions.txt 2> cppcheck-result.xml'
//                 publishCppcheck allowNoReport: true, ignoreBlankFiles: true, pattern: '**/cppcheck-result.xml'
//             }
//         }

//         stage('Deploy') {
//             when {
//                 environment name: 'DEPLOY', value: 'true'
//             }
//             steps {
//                 sh label: '', returnStatus: true, script: '''cp jenkinsexample ~
//                 cp test/testPro ~'''
//             }
//         }
	}

}
