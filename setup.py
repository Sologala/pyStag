from setuptools import setup
from setuptools.command.install import install
from distutils.sysconfig import get_python_lib
import glob
import shutil

__version__ = "0.0.1"
__library_file__ = './lib/pyStag.cpython-38-darwin.so'


class CopyLibFile(install):
    """"
    Directly copy library file to python's site-packages directory.
    """

    def run(self):
        install_dir = get_python_lib()
        lib_file = glob.glob(__library_file__)
        assert len(lib_file) == 1

        print('copying {} -> {}'.format(lib_file[0], install_dir))
        shutil.copy(lib_file[0], install_dir)

# The main interface is through Pybind11Extension.
# * You can add cxx_std=11/14/17, and then build_ext can be removed.
# * You can set include_pybind11=false to add the include directory yourself,
#   say from a submodule.
#
# Note:
#   Sort input source files if you glob sources to ensure bit-for-bit
#   reproducible builds (https://github.com/pybind/python_example/pull/53)


setup(
    name="pyStag",
    version=__version__,
    author="Sologala",
    author_email="dawsonwen123@gmail.com",
    url="None",
    description="warpping of Stag, a fiducial marker detection system",
    long_description="",
    extras_require={"test": "pytest"},
    # Currently, build_ext only provides an optional "highest supported C++
    # level" feature, but in the future it may provide more features.
    cmdclass={"install": CopyLibFile},
    zip_safe=False,
)
