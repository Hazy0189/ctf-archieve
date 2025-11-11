#!/bin/bash

VER=$1
PATCH_FILE=$2
NAME=${3:-$VER}

if [ -z "$VER" ]; then
    echo "Usage: $0 <commit_hash> <patch_file> [build_name]"
    exit 1
fi

cd /mnt/c/Users/dionf/v8/ || { echo "Failed to change directory"; exit 1; }

git checkout "$VER" || { echo "Failed to reset to commit $VER"; exit 1; }

gclient sync -D || { echo "Failed to sync dependencies"; exit 1; }

if [ -n "$PATCH_FILE" ]; then
    if [ -f "$PATCH_FILE" ]; then
        git apply \
            --ignore-space-change \
            --ignore-whitespace \
            --exclude=to_give/d8 \
            --exclude=to_give/snapshot_blob.bin \
            "$PATCH_FILE" || { echo "Failed to apply patch $PATCH_FILE"; exit 1; }
    else
        echo "Patch file $PATCH_FILE not found"
        exit 1
    fi
fi

gn gen out/x64_$NAME.release --args='is_component_build = false is_debug = false target_cpu = "x64" v8_enable_sandbox = false v8_enable_backtrace = true v8_enable_disassembler = true v8_enable_object_print = true dcheck_always_on = false use_goma = false v8_code_pointer_sandboxing = false' || { echo "Failed to generate build configuration"; exit 1; }

ninja -C out/x64_$NAME.release d8 || { echo "Build failed"; exit 1; }

echo "Build completed successfully"