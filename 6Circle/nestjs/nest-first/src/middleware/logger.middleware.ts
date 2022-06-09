import { Injectable, NestMiddleware } from "@nestjs/common";
import { Request, Response, NextFunction } from "express";

@Injectable()
export class LoggerMiddleware implements NestMiddleware {
    use(req: Request, res: Response, next: NextFunction) {
        console.log("Request...");
        next(); //중간에 미들웨어로 받으면 반드시 next햐줘야한다.
    }
}