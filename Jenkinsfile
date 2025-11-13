pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/illushha/Kursova_4lab_Lokotosh.git'
            }
        }

        stage('Build') {
            steps {
                bat '"C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\amd64\\MSBuild.exe" test_repos.sln /t:Rebuild /p:Configuration=Debug;Platform=x64'
            }
        }

        stage('Test') {
            steps {
                // запускаємо gtest і генеруємо XML-звіт
                bat 'x64\\Debug\\test_repos.exe --gtest_output=xml:x64\\Debug\\test_report.xml'
            }
        }
    }

    post {
        always {
            // підхоплюємо результат тестів і зберігаємо xml як артефакт
            junit 'x64/Debug/test_report.xml'
            archiveArtifacts artifacts: 'x64/Debug/test_report.xml', fingerprint: true
        }
    }
}
