{
  description = "cpp";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
          config.allowUnfree = true;
        };
      in
      {
        devShells.default = pkgs.mkShell {
          nativeBuildInputs = with pkgs; [
            gcc13
            gnumake
            cmake            
            zlib
            libffi
            clang-tools
            gtest
            pkg-config
            cpplint
          ];

          shellHook = ''
            export CXXFLAGS="-fopenmp -O3 -march=native -mtune=native $CXXFLAGS"
            export CFLAGS="-fopenmp -O3 -march=native -mtune=native $CFLAGS"
            export LDFLAGS="-fopenmp $LDFLAGS"
            
            export OMP_NUM_THREADS=8
            export OMP_PLACES=cores
            export OMP_PROC_BIND=spread

            echo "Threads: $OMP_NUM_THREADS"
          '';
        };
      }
    );
}
