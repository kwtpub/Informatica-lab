"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g = Object.create((typeof Iterator === "function" ? Iterator : Object).prototype);
    return g.next = verb(0), g["throw"] = verb(1), g["return"] = verb(2), typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
Object.defineProperty(exports, "__esModule", { value: true });
var readline = require("readline");
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});
function question(query) {
    return new Promise(function (resolve) {
        rl.question(query, resolve);
    });
}
function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
function inputMatrixFromKeyboard(n, m) {
    return __awaiter(this, void 0, void 0, function () {
        var matrix, i, j, input;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    matrix = [];
                    console.log('\nВведите элементы матрицы:');
                    i = 0;
                    _a.label = 1;
                case 1:
                    if (!(i < n)) return [3 /*break*/, 6];
                    matrix[i] = [];
                    j = 0;
                    _a.label = 2;
                case 2:
                    if (!(j < m)) return [3 /*break*/, 5];
                    return [4 /*yield*/, question("A[".concat(i, "][").concat(j, "] = "))];
                case 3:
                    input = _a.sent();
                    matrix[i][j] = parseFloat(input);
                    _a.label = 4;
                case 4:
                    j++;
                    return [3 /*break*/, 2];
                case 5:
                    i++;
                    return [3 /*break*/, 1];
                case 6: return [2 /*return*/, matrix];
            }
        });
    });
}
function generateRandomMatrix(n, m, min, max) {
    if (min === void 0) { min = 1; }
    if (max === void 0) { max = 100; }
    var matrix = [];
    for (var i = 0; i < n; i++) {
        matrix[i] = [];
        for (var j = 0; j < m; j++) {
            matrix[i][j] = getRandomInt(min, max);
        }
    }
    return matrix;
}
function printMatrix(matrix, name) {
    console.log("\n".concat(name, ":"));
    for (var i = 0; i < matrix.length; i++) {
        console.log(matrix[i].join('\t'));
    }
}
function main() {
    return __awaiter(this, void 0, void 0, function () {
        var nInput, mInput, n, m, choice, A, B, i, max, min, j, error_1;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    _a.trys.push([0, 7, 8, 9]);
                    return [4 /*yield*/, question('Введите количество строк n: ')];
                case 1:
                    nInput = _a.sent();
                    return [4 /*yield*/, question('Введите количество столбцов m: ')];
                case 2:
                    mInput = _a.sent();
                    n = parseInt(nInput, 10);
                    m = parseInt(mInput, 10);
                    if (isNaN(n) || isNaN(m) || n <= 0 || m <= 0) {
                        console.log('Ошибка: размеры матрицы должны быть положительными числами');
                        rl.close();
                        return [2 /*return*/];
                    }
                    return [4 /*yield*/, question('\nВыберите способ ввода:\n1 - с клавиатуры\n2 - случайным образом\nВаш выбор: ')];
                case 3:
                    choice = _a.sent();
                    A = void 0;
                    if (!(choice === '1')) return [3 /*break*/, 5];
                    return [4 /*yield*/, inputMatrixFromKeyboard(n, m)];
                case 4:
                    A = _a.sent();
                    return [3 /*break*/, 6];
                case 5:
                    if (choice === '2') {
                        A = generateRandomMatrix(n, m);
                    }
                    else {
                        console.log('Неверный выбор, используется случайная генерация');
                        A = generateRandomMatrix(n, m);
                    }
                    _a.label = 6;
                case 6:
                    // Вывод исходной матрицы
                    printMatrix(A, 'Исходная матрица A');
                    B = [];
                    for (i = 0; i < n; i++) {
                        max = A[i][0];
                        min = A[i][0];
                        // Поиск максимального и минимального элементов в строке
                        for (j = 1; j < m; j++) {
                            if (A[i][j] > max) {
                                max = A[i][j];
                            }
                            if (A[i][j] < min) {
                                min = A[i][j];
                            }
                        }
                        // Вычисление разности
                        B[i] = max - min;
                        // Вывод промежуточного результата
                        console.log("\n\u0421\u0442\u0440\u043E\u043A\u0430 ".concat(i, ": max = ").concat(max, ", min = ").concat(min, ", B[").concat(i, "] = ").concat(B[i]));
                    }
                    // Вывод итогового массива B
                    console.log('\nИтоговый массив B:');
                    console.log(B.join(', '));
                    return [3 /*break*/, 9];
                case 7:
                    error_1 = _a.sent();
                    console.error('Ошибка:', error_1);
                    return [3 /*break*/, 9];
                case 8:
                    rl.close();
                    return [7 /*endfinally*/];
                case 9: return [2 /*return*/];
            }
        });
    });
}
main();
