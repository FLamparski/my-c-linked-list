module.exports = (grunt) ->
  require('time-grunt')(grunt)
  flags = [
    '-Wall',
    '-Wextra',
    '--std=c11',
    '-x', 'c',
    '-isystem',
    '/usr/include',
    '-isystem',
    '/usr/local/include'
  ]

  grunt.initConfig
    pkg: grunt.file.readJSON 'package.json'
    shell:
      compile:
        command: "clang #{flags.join(' ')}
        #{grunt.file.expand([ '**/*.c', '**/*.h' ]).join(' ')}
        -o <%= pkg.scripts.test %>"
      valgrind:
        command: "valgrind ./<%= pkg.scripts.test %>"
      run:
        command: './lltest'
    watch:
      all:
        files: [ 'Gruntfile.coffee', '**/*.c', '**/*.h' ]
        tasks: [ 'shell:compile', 'shell:valgrind' ]

  grunt.loadNpmTasks 'grunt-shell'
  grunt.loadNpmTasks 'grunt-contrib-watch'
  grunt.registerTask 'default', [ 'shell:compile', 'shell:run', 'watch' ]
