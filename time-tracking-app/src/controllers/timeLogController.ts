class TimeLogController {
    constructor(private timeLogService: any) {}

    createTimeLog(req: any, res: any) {
        const timeLogData = req.body;
        this.timeLogService.saveTimeLog(timeLogData)
            .then((timeLog: any) => res.status(201).json(timeLog))
            .catch((error: any) => res.status(500).json({ error: error.message }));
    }

    getTimeLogs(req: any, res: any) {
        this.timeLogService.fetchTimeLogs()
            .then((timeLogs: any) => res.status(200).json(timeLogs))
            .catch((error: any) => res.status(500).json({ error: error.message }));
    }

    deleteTimeLog(req: any, res: any) {
        const { id } = req.params;
        this.timeLogService.removeTimeLog(id)
            .then(() => res.status(204).send())
            .catch((error: any) => res.status(500).json({ error: error.message }));
    }
}

export default TimeLogController;