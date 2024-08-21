(module
  (type (;0;) (func))
  (type (;1;) (func (param i32 i32) (result i32)))
  (type (;2;) (func (result i32)))
  (type (;3;) (func (param i32 i32)))
  (func (;0;) (type 0))
  (func (;1;) (type 1) (param i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    local.set 2
    i32.const 32
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    local.get 4
    local.get 0
    i32.store offset=24
    local.get 4
    local.get 1
    i32.store offset=20
    local.get 4
    i32.load offset=24
    local.set 5
    local.get 4
    local.get 5
    i32.store offset=16
    local.get 4
    i32.load offset=20
    local.set 6
    local.get 4
    local.get 6
    i32.store offset=12
    block  ;; label = @1
      loop  ;; label = @2
        local.get 4
        i32.load offset=16
        local.set 7
        i32.const 1
        local.set 8
        local.get 7
        local.get 8
        i32.add
        local.set 9
        local.get 4
        local.get 9
        i32.store offset=16
        local.get 7
        i32.load8_u
        local.set 10
        local.get 4
        local.get 10
        i32.store8 offset=11
        local.get 4
        i32.load offset=12
        local.set 11
        i32.const 1
        local.set 12
        local.get 11
        local.get 12
        i32.add
        local.set 13
        local.get 4
        local.get 13
        i32.store offset=12
        local.get 11
        i32.load8_u
        local.set 14
        local.get 4
        local.get 14
        i32.store8 offset=10
        local.get 4
        i32.load8_u offset=11
        local.set 15
        i32.const 255
        local.set 16
        local.get 15
        local.get 16
        i32.and
        local.set 17
        block  ;; label = @3
          local.get 17
          br_if 0 (;@3;)
          local.get 4
          i32.load8_u offset=11
          local.set 18
          i32.const 255
          local.set 19
          local.get 18
          local.get 19
          i32.and
          local.set 20
          local.get 4
          i32.load8_u offset=10
          local.set 21
          i32.const 255
          local.set 22
          local.get 21
          local.get 22
          i32.and
          local.set 23
          local.get 20
          local.get 23
          i32.sub
          local.set 24
          local.get 4
          local.get 24
          i32.store offset=28
          br 2 (;@1;)
        end
        local.get 4
        i32.load8_u offset=11
        local.set 25
        i32.const 255
        local.set 26
        local.get 25
        local.get 26
        i32.and
        local.set 27
        local.get 4
        i32.load8_u offset=10
        local.set 28
        i32.const 255
        local.set 29
        local.get 28
        local.get 29
        i32.and
        local.set 30
        local.get 27
        local.set 31
        local.get 30
        local.set 32
        local.get 31
        local.get 32
        i32.eq
        local.set 33
        i32.const 1
        local.set 34
        local.get 33
        local.get 34
        i32.and
        local.set 35
        local.get 35
        br_if 0 (;@2;)
      end
      local.get 4
      i32.load8_u offset=11
      local.set 36
      i32.const 255
      local.set 37
      local.get 36
      local.get 37
      i32.and
      local.set 38
      local.get 4
      i32.load8_u offset=10
      local.set 39
      i32.const 255
      local.set 40
      local.get 39
      local.get 40
      i32.and
      local.set 41
      local.get 38
      local.get 41
      i32.sub
      local.set 42
      local.get 4
      local.get 42
      i32.store offset=28
    end
    local.get 4
    i32.load offset=28
    local.set 43
    local.get 43
    return)
  (func (;2;) (type 2) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    local.set 0
    i32.const 16
    local.set 1
    local.get 0
    local.get 1
    i32.sub
    local.set 2
    local.get 2
    global.set 0
    i32.const 0
    local.set 3
    local.get 2
    local.get 3
    i32.store offset=12
    block  ;; label = @1
      loop  ;; label = @2
        local.get 2
        i32.load offset=12
        local.set 4
        local.get 4
        i32.load8_u offset=1072
        local.set 5
        i32.const 24
        local.set 6
        local.get 5
        local.get 6
        i32.shl
        local.set 7
        local.get 7
        local.get 6
        i32.shr_s
        local.set 8
        local.get 8
        i32.eqz
        br_if 1 (;@1;)
        i32.const 0
        local.set 9
        local.get 2
        i32.load offset=12
        local.set 10
        local.get 10
        i32.load8_u offset=1072
        local.set 11
        i32.const 24
        local.set 12
        local.get 11
        local.get 12
        i32.shl
        local.set 13
        local.get 13
        local.get 12
        i32.shr_s
        local.set 14
        i32.const 20
        local.set 15
        local.get 14
        local.get 15
        i32.xor
        local.set 16
        local.get 10
        local.get 16
        i32.store8 offset=1072
        local.get 2
        i32.load offset=12
        local.set 17
        local.get 17
        local.set 18
        local.get 9
        local.set 19
        local.get 18
        local.get 19
        i32.gt_s
        local.set 20
        i32.const 1
        local.set 21
        local.get 20
        local.get 21
        i32.and
        local.set 22
        block  ;; label = @3
          local.get 22
          i32.eqz
          br_if 0 (;@3;)
          local.get 2
          i32.load offset=12
          local.set 23
          i32.const 1
          local.set 24
          local.get 23
          local.get 24
          i32.sub
          local.set 25
          local.get 25
          i32.load8_u offset=1072
          local.set 26
          i32.const 24
          local.set 27
          local.get 26
          local.get 27
          i32.shl
          local.set 28
          local.get 28
          local.get 27
          i32.shr_s
          local.set 29
          local.get 2
          i32.load offset=12
          local.set 30
          local.get 30
          i32.load8_u offset=1072
          local.set 31
          i32.const 24
          local.set 32
          local.get 31
          local.get 32
          i32.shl
          local.set 33
          local.get 33
          local.get 32
          i32.shr_s
          local.set 34
          local.get 34
          local.get 29
          i32.xor
          local.set 35
          local.get 30
          local.get 35
          i32.store8 offset=1072
        end
        i32.const 2
        local.set 36
        local.get 2
        i32.load offset=12
        local.set 37
        local.get 37
        local.set 38
        local.get 36
        local.set 39
        local.get 38
        local.get 39
        i32.gt_s
        local.set 40
        i32.const 1
        local.set 41
        local.get 40
        local.get 41
        i32.and
        local.set 42
        block  ;; label = @3
          local.get 42
          i32.eqz
          br_if 0 (;@3;)
          local.get 2
          i32.load offset=12
          local.set 43
          i32.const 3
          local.set 44
          local.get 43
          local.get 44
          i32.sub
          local.set 45
          local.get 45
          i32.load8_u offset=1072
          local.set 46
          i32.const 24
          local.set 47
          local.get 46
          local.get 47
          i32.shl
          local.set 48
          local.get 48
          local.get 47
          i32.shr_s
          local.set 49
          local.get 2
          i32.load offset=12
          local.set 50
          local.get 50
          i32.load8_u offset=1072
          local.set 51
          i32.const 24
          local.set 52
          local.get 51
          local.get 52
          i32.shl
          local.set 53
          local.get 53
          local.get 52
          i32.shr_s
          local.set 54
          local.get 54
          local.get 49
          i32.xor
          local.set 55
          local.get 50
          local.get 55
          i32.store8 offset=1072
        end
        local.get 2
        i32.load offset=12
        local.set 56
        i32.const 10
        local.set 57
        local.get 56
        local.get 57
        i32.rem_s
        local.set 58
        local.get 2
        i32.load offset=12
        local.set 59
        local.get 59
        i32.load8_u offset=1072
        local.set 60
        i32.const 24
        local.set 61
        local.get 60
        local.get 61
        i32.shl
        local.set 62
        local.get 62
        local.get 61
        i32.shr_s
        local.set 63
        local.get 63
        local.get 58
        i32.xor
        local.set 64
        local.get 59
        local.get 64
        i32.store8 offset=1072
        local.get 2
        i32.load offset=12
        local.set 65
        i32.const 2
        local.set 66
        local.get 65
        local.get 66
        i32.rem_s
        local.set 67
        block  ;; label = @3
          block  ;; label = @4
            local.get 67
            br_if 0 (;@4;)
            local.get 2
            i32.load offset=12
            local.set 68
            local.get 68
            i32.load8_u offset=1072
            local.set 69
            i32.const 24
            local.set 70
            local.get 69
            local.get 70
            i32.shl
            local.set 71
            local.get 71
            local.get 70
            i32.shr_s
            local.set 72
            i32.const 9
            local.set 73
            local.get 72
            local.get 73
            i32.xor
            local.set 74
            local.get 68
            local.get 74
            i32.store8 offset=1072
            br 1 (;@3;)
          end
          local.get 2
          i32.load offset=12
          local.set 75
          local.get 75
          i32.load8_u offset=1072
          local.set 76
          i32.const 24
          local.set 77
          local.get 76
          local.get 77
          i32.shl
          local.set 78
          local.get 78
          local.get 77
          i32.shr_s
          local.set 79
          i32.const 8
          local.set 80
          local.get 79
          local.get 80
          i32.xor
          local.set 81
          local.get 75
          local.get 81
          i32.store8 offset=1072
        end
        local.get 2
        i32.load offset=12
        local.set 82
        i32.const 3
        local.set 83
        local.get 82
        local.get 83
        i32.rem_s
        local.set 84
        block  ;; label = @3
          block  ;; label = @4
            local.get 84
            br_if 0 (;@4;)
            local.get 2
            i32.load offset=12
            local.set 85
            local.get 85
            i32.load8_u offset=1072
            local.set 86
            i32.const 24
            local.set 87
            local.get 86
            local.get 87
            i32.shl
            local.set 88
            local.get 88
            local.get 87
            i32.shr_s
            local.set 89
            i32.const 7
            local.set 90
            local.get 89
            local.get 90
            i32.xor
            local.set 91
            local.get 85
            local.get 91
            i32.store8 offset=1072
            br 1 (;@3;)
          end
          i32.const 1
          local.set 92
          local.get 2
          i32.load offset=12
          local.set 93
          i32.const 3
          local.set 94
          local.get 93
          local.get 94
          i32.rem_s
          local.set 95
          local.get 95
          local.set 96
          local.get 92
          local.set 97
          local.get 96
          local.get 97
          i32.eq
          local.set 98
          i32.const 1
          local.set 99
          local.get 98
          local.get 99
          i32.and
          local.set 100
          block  ;; label = @4
            block  ;; label = @5
              local.get 100
              i32.eqz
              br_if 0 (;@5;)
              local.get 2
              i32.load offset=12
              local.set 101
              local.get 101
              i32.load8_u offset=1072
              local.set 102
              i32.const 24
              local.set 103
              local.get 102
              local.get 103
              i32.shl
              local.set 104
              local.get 104
              local.get 103
              i32.shr_s
              local.set 105
              i32.const 6
              local.set 106
              local.get 105
              local.get 106
              i32.xor
              local.set 107
              local.get 101
              local.get 107
              i32.store8 offset=1072
              br 1 (;@4;)
            end
            local.get 2
            i32.load offset=12
            local.set 108
            local.get 108
            i32.load8_u offset=1072
            local.set 109
            i32.const 24
            local.set 110
            local.get 109
            local.get 110
            i32.shl
            local.set 111
            local.get 111
            local.get 110
            i32.shr_s
            local.set 112
            i32.const 5
            local.set 113
            local.get 112
            local.get 113
            i32.xor
            local.set 114
            local.get 108
            local.get 114
            i32.store8 offset=1072
          end
        end
        local.get 2
        i32.load offset=12
        local.set 115
        i32.const 1
        local.set 116
        local.get 115
        local.get 116
        i32.add
        local.set 117
        local.get 2
        local.get 117
        i32.store offset=12
        br 0 (;@2;)
      end
    end
    i32.const 0
    local.set 118
    local.get 2
    local.get 118
    i32.store offset=4
    block  ;; label = @1
      loop  ;; label = @2
        local.get 2
        i32.load offset=4
        local.set 119
        local.get 2
        i32.load offset=12
        local.set 120
        local.get 119
        local.set 121
        local.get 120
        local.set 122
        local.get 121
        local.get 122
        i32.lt_s
        local.set 123
        i32.const 1
        local.set 124
        local.get 123
        local.get 124
        i32.and
        local.set 125
        local.get 125
        i32.eqz
        br_if 1 (;@1;)
        local.get 2
        i32.load offset=4
        local.set 126
        i32.const 2
        local.set 127
        local.get 126
        local.get 127
        i32.rem_s
        local.set 128
        block  ;; label = @3
          local.get 128
          br_if 0 (;@3;)
          local.get 2
          i32.load offset=4
          local.set 129
          i32.const 1
          local.set 130
          local.get 129
          local.get 130
          i32.add
          local.set 131
          local.get 2
          i32.load offset=12
          local.set 132
          local.get 131
          local.set 133
          local.get 132
          local.set 134
          local.get 133
          local.get 134
          i32.lt_s
          local.set 135
          i32.const 1
          local.set 136
          local.get 135
          local.get 136
          i32.and
          local.set 137
          local.get 137
          i32.eqz
          br_if 0 (;@3;)
          local.get 2
          i32.load offset=4
          local.set 138
          local.get 138
          i32.load8_u offset=1072
          local.set 139
          local.get 2
          local.get 139
          i32.store8 offset=11
          local.get 2
          i32.load offset=4
          local.set 140
          i32.const 1
          local.set 141
          local.get 140
          local.get 141
          i32.add
          local.set 142
          local.get 142
          i32.load8_u offset=1072
          local.set 143
          local.get 2
          i32.load offset=4
          local.set 144
          local.get 144
          local.get 143
          i32.store8 offset=1072
          local.get 2
          i32.load8_u offset=11
          local.set 145
          local.get 2
          i32.load offset=4
          local.set 146
          i32.const 1
          local.set 147
          local.get 146
          local.get 147
          i32.add
          local.set 148
          local.get 148
          local.get 145
          i32.store8 offset=1072
        end
        local.get 2
        i32.load offset=4
        local.set 149
        i32.const 1
        local.set 150
        local.get 149
        local.get 150
        i32.add
        local.set 151
        local.get 2
        local.get 151
        i32.store offset=4
        br 0 (;@2;)
      end
    end
    i32.const 0
    local.set 152
    i32.const 1072
    local.set 153
    i32.const 1024
    local.set 154
    local.get 154
    local.get 153
    call 1
    local.set 155
    local.get 155
    local.set 156
    local.get 152
    local.set 157
    local.get 156
    local.get 157
    i32.ne
    local.set 158
    i32.const -1
    local.set 159
    local.get 158
    local.get 159
    i32.xor
    local.set 160
    i32.const 1
    local.set 161
    local.get 160
    local.get 161
    i32.and
    local.set 162
    i32.const 16
    local.set 163
    local.get 2
    local.get 163
    i32.add
    local.set 164
    local.get 164
    global.set 0
    local.get 162
    return)
  (func (;3;) (type 3) (param i32 i32)
    (local i32 i32 i32 i32 i32)
    global.get 0
    local.set 2
    i32.const 16
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    local.get 4
    local.get 0
    i32.store offset=12
    local.get 4
    local.get 1
    i32.store offset=8
    local.get 4
    i32.load offset=12
    local.set 5
    local.get 4
    i32.load offset=8
    local.set 6
    local.get 6
    local.get 5
    i32.store8 offset=1072
    return)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 2)
  (global (;0;) (mut i32) (i32.const 66864))
  (global (;1;) i32 (i32.const 1072))
  (global (;2;) i32 (i32.const 1024))
  (global (;3;) i32 (i32.const 1328))
  (global (;4;) i32 (i32.const 1024))
  (global (;5;) i32 (i32.const 66864))
  (global (;6;) i32 (i32.const 0))
  (global (;7;) i32 (i32.const 1))
  (export "memory" (memory 0))
  (export "__wasm_call_ctors" (func 0))
  (export "strcmp" (func 1))
  (export "check_flag" (func 2))
  (export "input" (global 1))
  (export "copy_char" (func 3))
  (export "__dso_handle" (global 2))
  (export "__data_end" (global 3))
  (export "__global_base" (global 4))
  (export "__heap_base" (global 5))
  (export "__memory_base" (global 6))
  (export "__table_base" (global 7))
  (data (;0;) (i32.const 1024) "\18j|a\118i7F[#\06fJV:\0d\1c\12/dd\11Vu\0fn\1b\068\07E\10/o?\13\02+\09^\00\00"))
