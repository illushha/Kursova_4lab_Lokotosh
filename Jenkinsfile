pipeline {
  agent any
  options { timestamps() }

  environment {
    // MSBuild – той самий, що ти запускaв у терміналі
    MSBUILD = 'C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\amd64\\MSBuild.exe'

    SLN      = 'test_repos.sln'
    CONFIG   = 'Debug'
    PLATFORM = 'x64'

    TEST_EXE = 'x64\\Debug\\test_repos.exe'      // тут назва твого exe
    XML_OUT  = 'x64\\Debug\\test_report.xml'
  }

  stages {
    stage('Checkout') {
      steps {
        checkout scm
      }
    }

    stage('Build') {
      steps {
        bat "\"%MSBUILD%\" %SLN% /t:Rebuild \"/p:Configuration=%CONFIG%;Platform=%PLATFORM%\""
      }
    }

    stage('Test') {
      steps {
        bat "%TEST_EXE% --gtest_output=xml:%XML_OUT%"
      }
    }
  }

  post {
    always {
      xunit tools: [GoogleTest(
        pattern: 'x64/Debug/*.xml',
        deleteOutputFiles: true,
        failIfNotNew: false,
        skipNoTestFiles: true,
        stopProcessingIfError: false
      )]

      archiveArtifacts artifacts: 'x64/Debug/test_report.xml', fingerprint: true, onlyIfSuccessful: false
    }
  }
}
